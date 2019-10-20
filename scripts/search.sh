#Searching for keywords!!
grep -R "secure_reg" ~/Documents/* > log

input="/home/parallels/Documents/Chip_Security_Advanced_Project/scripts/log"
while IFS= read -r line
do
  echo "$line"
done < "$input"
