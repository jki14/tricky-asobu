#! /bin/bash

# add *.h files
find . -name '*.h' -not -path './.git/*' -exec git add {} \;

# add *.c files
find . -name '*.c' -not -path './.git/*' -exec git add {} \;

#add *.cpp files
find . -name '*.cpp' -not -path './.git/*' -exec git add {} \;

#add *.hpp files
find . -name '*.hpp' -not -path './.git/*' -exec git add {} \;

#add *.java files
find . -name '*.java' -not -path './.git/*' -exec git add {} \;

#add *.py files
find . -name '*.py' -not -path './.git/*' -exec git add {} \;

#add *.html files
find . -name '*.html' -not -path './.git/*' -exec git add {} \;

#add *.scala files
find . -name '*.scala' -not -path './.git/*' -exec git add {} \;

#add *.lua files
find . -name '*.lua' -not -path './.git/*' -exec git add {} \;

#add *.conf files
find . -name '*.conf' -not -path './.git/*' -exec git add {} \;

#add *.sample files
find . -name '*.sample' -not -path './.git/*' -exec git add {} \;

#add *.tex files
find . -name '*.tex' -not -path './.git/*' -exec git add {} \;

#add *.otf files
find . -name '*.otf' -not -path './.git/*' -exec git add {} \;

#add .gitignore 
git add .gitignore

#add README.md
git add README.md

#add gadd.sh
git add gadd.sh
