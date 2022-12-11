g++ -std=c++2a $1/sol.cpp -o main -fsplit-stack -Wall -Wextra -Wshadow
echo "---- test result ----"
cat $1/test.inp | ./main
