echo "Enter the no.of terms you need in fibonocci series"
read num
x=0
y=1
echo "Series :"
for((i=0;i<=num;i++))
 do 
   echo $x
   f=$(($x+$y))
   x=$y
   y=$f
 done
