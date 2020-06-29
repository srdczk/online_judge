read n

sum=0

for ((i=0; i<n; ++i))
do
    read x
    sum=$[${sum} + ${x}]
done

res=$(echo "${sum} / ${n}" | bc -l)

printf "%.3f" ${res}
