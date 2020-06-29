j=49
# for i in {0..49}
for ((i=0; i<=j; ++i))
do
    p=$[2*$i+1]
    echo ${p}
done