# 実行
# bash b_rand.sh

GRE='\033[32m'
YEL='\033[33m'
RES='\033[0m'

# --- 再コンパイルは適宜

g++ -D ONLINE_JUDGE 227a.cpp -I.
g++ -D ONLINE_JUDGE b_naive.cpp -I. -o naive

# --- 

cnt=1
while true; do
  python3 b_gen.py > c_in.txt
  ./a.out < c_in.txt > c_out1.txt
  ./naive < c_in.txt > c_out2.txt
  if ! diff c_out1.txt c_out2.txt; then
    echo -e "${YEL}WA${RES}"
    break
  else
    echo -e "${GRE}AC${RES} $cnt"
    ((cnt++))
  fi
done