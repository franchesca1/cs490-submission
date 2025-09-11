
#REGEX
#[:alnum:] Example
#[:punc:] Example
#[:alpha:]
#Meta characters, which allow to design complex patterns
#.(dot) -> matches any single character
#Character classes: matches a specific set of characters within []
#-> [aeiou] matches for any single character within []
#-> Ranges can be specified like [0-9] or [a-d]
#-> -(hyphen) has a special meaning in character class ranges, if the start or end is missing, then hyphen will be treated as a literal character
#-> Named character cases, portability across languages
#   -> lower, upper, alnum, digit, punct, cntrl, alpha etc
#   -> Syntax: [[:upper:]]
#-> you can also negate (ignore) a match using [^]
#-> Anchors: allows us to match the beginning or the end of the line
#   ->^ match the beginning of the line
#   ->$ match the end of the line
#-> Repititions: when using repititions, the match will be that of the longest possible string
#   -> *(start): match zero or more occurrences of the immediately preceding character
#   -> Ranges can also be limited using {}
#      -> {N} : matches for exactly N times  ya{5}y  ->  needs exactly 5 a's
#      -> {N, M} : match at least N times and at most M times     ya{1, 5}y   at least 1 a but at most 5 a's
#      -> {,M} : matches at most M times
#      -> {N,} : matches at least N times and at most infinity times
#Sub expressions: treated as a single character, so that the * or {} can be applied to more than one character. We use ()
#Back references: used to match the sub expression that was made earlier
#   ->to refer we use \n. Where n is the position number
#   ->\1 \2 \3
#2 types of regex-> BRE(Basic Regex) and ERE(Extended Regular Expressions)
#There is also PCRE(Perl Compatible Regex)
#Extended meta characters:offers a richer set of special characters
#   -> + (one or more occurrence) of the immediate proceeding character
#   -> ? (optional) matches 0 or 1 occurrence of the immediate proceeding character
#   Note: *, +, ?, {} are referred to as quantifiers, because they specify the quantity of the match
#   ->alternation: matches one or another substring. We use |
#   ->Example: ^(from|subject)
#