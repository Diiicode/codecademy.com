# 1) Print the working directory
pwd

# 2) Create and open hello.txt in nano
nano hello.txt
# 3) Inside nano, type exactly:
# Hello, I am nano
# Save + exit: Ctrl+O, Enter, Ctrl+X
clear

# 4) Open your shell profile (zsh users use ~/.zshrc)
nano ~/.bashrc

# 5) Add this line to the end of the file, save & exit:
# echo "Hello"
clear

# 6) Reload the profile so the greeting runs now
source ~/.bashrc   # (or: source ~/.zshrc)
# You should see: Hello

# 7) Open the profile again to add aliases
nano ~/.bashrc
# Add these two lines anywhere (end is fine):
# alias p='pwd'
# alias ll='ls -la'
# Save & exit
clear

# 8) Reload profile to activate aliases
source ~/.bashrc

# 9) Test aliases
p
ll

# 10) Open profile to set USER env var (use your name)
nano ~/.bashrc
# Add:
# export USER="Diogo"
# Save & exit
clear

# 11) Reload profile (activates the change)
source ~/.bashrc

# 12) Echo USER
echo "$USER"

# 13) Open profile to set the prompt
nano ~/.bashrc
# Add:
# export PS1=">> "
# (zsh users can also do: export PROMPT=">> ")
# Save & exit
clear

# 14) Reload profile to apply the prompt
source ~/.bashrc

# 15) Try the aliases again with the new prompt
p
ll

# 16) Echo HOME
echo "$HOME"

# 17) Echo PATH
echo "$PATH"

# 18) List all environment variables
env
