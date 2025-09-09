#!/bin/bash

API_URL="https://student-info-api.netlify.app/.netlify/functions/submit_student_info"

read -p "UCID: " id_number
read -p "First Name: " first_name
read -p "Last Name: " last_name
read -p "GitHub Username: " github_username
read -p "Discord Username: " discord_username
read -p "Favorite Cartoon: " favorite_cartoon
read -p "Favorite Programming Language: " program_language
read -p "Favorite Movie/Game/Book: " favorite_item
read -p "Section (101 or 103): " section

section="$(printf '%s' "$section" | tr -d '\r' | sed -E 's/^[[:space:]]+|[[:space:]]+$//g')"

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
    FavoriteCartoon:$toon, FavoriteProgrammingLanguage:$lang, FavoriteMedia:$fav,
    section:$section}')  

#curl -sS -X POST "$API_URL" \
#  -H "Content-Type: application/json" \
#  --data "$JSON"
#echo




