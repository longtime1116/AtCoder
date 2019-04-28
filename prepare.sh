mkdir $1
if [ $? -eq 0 ]; then
  cp ./template.cpp ./$1/a.cpp
  cp ./template.cpp ./$1/b.cpp
  cp ./template.cpp ./$1/c.cpp
  cp ./template.cpp ./$1/d.cpp
  cd $1
fi
