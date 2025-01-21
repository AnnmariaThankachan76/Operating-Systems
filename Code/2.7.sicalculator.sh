echo "Enter the first number "
read num1
echo "Enter the second number "
read num2
echo " Enter 1 for addition"
echo " Enter 2 for subtraction"
echo " Enter 3 for multiplication"
echo " Enter 4 for division"
echo "Write your choice "
read operator
echo "The result is :"
case $operator in
1)rs=$(($num1+$num2))
   echo $rs;;
2)rs=$(($num1-$num2))
   echo $rs;;
3)rs=$(($num1*$num2))
   echo $rs;;
4)rs=$(($num1/$num2))
   echo $rs;;
*) echo "Invalid choice ";;
esac
