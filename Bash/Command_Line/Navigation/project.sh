# 1) Print the working directory
pwd

# 2) List all files/dirs in long format, including hidden
ls -la

# 3) View contents of basketball.txt
cat basketball.txt

# 4) View contents of hockey.txt
cat hockey.txt

# 5) Redirect basketball.txt into hockey.txt, then view hockey.txt
cat basketball.txt > hockey.txt
cat hockey.txt

# 6) View contents of lacrosse.txt
cat lacrosse.txt

# 7) Append lacrosse.txt to tennis.txt, then view tennis.txt
cat lacrosse.txt >> tennis.txt
cat tennis.txt

# 8) Use gymnastics.txt as stdin to cat
cat < gymnastics.txt

# 9) Pipe lacrosse.txt through word count
cat lacrosse.txt | wc

# 10) View equipment.txt
cat equipment.txt

# 11) Sort equipment.txt alphabetically (show sorted output)
sort equipment.txt
# (optional) save the sorted result to a new file:
# sort equipment.txt > equipment_sorted.txt

# 12) Remove adjacent duplicates in equipment.txt
# If duplicates are already adjacent:
uniq equipment.txt
# Safer (sort first so duplicates become adjacent):
# sort equipment.txt | uniq

# 13) Search roster.txt for players from Japan
grep 'Japan' roster.txt

# 14) Search current directory for the string 'player' (show filenames and line numbers)
grep -Rni 'player' .

# 15) View games.txt, then replace 'loss' with 'win' in the file
cat games.txt
sed -i 's/loss/win/g' games.txt   # (Linux sed; on macOS use: sed -i '' 's/loss/win/g' games.txt)
cat games.txt
