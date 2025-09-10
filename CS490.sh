#!/bin/bash

API_URL="https://student-info-api.netlify.app/.netlify/functions/submit_student_info"

#Help from ChatGPT for some reason it kept giving me an error for section but they offered the soltuion of clean() and nonempty()
clean() { printf '%s' "$1" | tr -d '\r' | sed -E 's/^[[:space:]]+|[[:space:]]+$//g'; }
nonempty() { [ -n "$2" ] || { echo "Error: $1 cannot be empty."; exit 1; }; }


read -p "UCID: " id_number
read -p "First Name: " first_name
read -p "Last Name: " last_name
read -p "GitHub Username: " github_username
read -p "Discord Username: " discord_username
read -p "Favorite Cartoon: " favorite_cartoon
read -p "Favorite Programming Language: " program_language
read -p "Favorite Movie/Game/Book: " favorite_item
read -p "Section (101 or 103): " section

id_number=$(clean "$id_number")
first_name=$(clean "$first_name")
last_name=$(clean "$last_name")
github_username=$(clean "$github_username")
discord_username=$(clean "$discord_username")
favorite_cartoon=$(clean "$favorite_cartoon")
program_language=$(clean "$program_language")
favorite_item=$(clean "$favorite_item")
section=$(clean "$section")


nonempty "UCID" "$id_number"
nonempty "First Name" "$first_name"
nonempty "Last Name" "$last_name"
nonempty "GitHub Username" "$github_username"
nonempty "Discord Username" "$discord_username"
nonempty "Favorite Cartoon" "$favorite_cartoon"
nonempty "Favorite Programming Language" "$program_language"
nonempty "Favorite Movie/Game/Book" "$favorite_item"
nonempty "Section" "$section"

if ! [[ "$id_number" =~ ^[A-Za-z]{2,}[0-9]+$ ]]; then
  echo "Warning: UCID doesn't look like right."
fi

case "$section" in
  101|103) ;;
  *) echo 'Error: Section must be 101 or 103.'; exit 1 ;;
esac

# Help from ChatGPT github was pretty hard to make sure there were no errors
gh_code=$(curl -s -o /dev/null -w "%{http_code}" "https://api.github.com/users/$github_username")
if [ "$gh_code" != "200" ]; then
  echo "Warning: GitHub user '$github_username' not found (make sure your repo has this script)."
fi

#delete to make sure there are no duplicates
curl -sS -G -X DELETE "$API_URL" \
  --data-urlencode "UCID=$id_number" \
  --data-urlencode "section=$section" >/dev/null


JSON=$(jq -n \
  --arg ucid "$id_number" \
  --arg first "$first_name" \
  --arg last "$last_name" \
  --arg gh "$github_username" \
  --arg disc "$discord_username" \
  --arg toon "$favorite_cartoon" \
  --arg lang "$program_language" \
  --arg fav "$favorite_item" \
  --arg section "$section" \
  '{UCID:$ucid, FirstName:$first, LastName:$last, GitHubUsername:$gh, DiscordUsername:$disc,
    FavoriteCartoon:$toon, FavoriteProgrammingLanguage:$lang, FavoriteMedia:$fav, section:$section}')


resp=$(mktemp)
code=$(curl -sS -o "$resp" -w "%{http_code}" \
  -X POST "$API_URL" -H "Content-Type: application/json" --data "$JSON")
echo "HTTP $code"
cat "$resp"; echo
rm -f "$resp"





