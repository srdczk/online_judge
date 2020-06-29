read x

res=$(echo "${x}" | bc -l)

printf "%.3f" ${res}


