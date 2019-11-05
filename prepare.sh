mkdir $1
if [ $? -eq 0 ]; then
  if [ $# -eq 1 ]; then
    cp ./template.cpp ./$1/a.cpp
    cp ./template.cpp ./$1/b.cpp
    cp ./template.cpp ./$1/c.cpp
    cp ./template.cpp ./$1/d.cpp
    cp ./template.cpp ./$1/e.cpp
    cp ./template.cpp ./$1/f.cpp
    cd $1
  elif [ $# -eq 2 ]; then
    cp ./template.cpp ./$1/$2.cpp
    cd $1
  else
    rm -r $1
  fi
fi
