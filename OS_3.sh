#!/bin/bash
function Fsumm {
ans=$(($1 + $2))
echo $ans
}
function Fdiff {
ans=$(($1 - $2))
echo $ans
}
# Создал функцию для перемножения а на б
function Fmultiply{
    ans=$(($1 * $2))
    echo $ans
}
# Создал функцию для деления а на б
function Fdivide{
    ans=$(($1 / $2))
    echo $ans
}

while :
do
echo "Enter a"
read a
echo "Enter b"
read b
echo "Enter sign"
read c
case $c in
+)
ans=$(Fsumm $a $b);;
-)
ans=$(Fdiff $a $b);;
x)                          #Добавил в case выбор умножения через x
ans=$(Fmultiply $a $b);;
/)                          #Добавил в case выбор умножения через /
ans=$(Fdivide $a $b);;
*)                          #case default
echo Error sign
exit
esac
echo Expr = $ans
if [ $(expr $ans % 5) -eq 0 ] #Проверка на кратность 5, если остаток 0, то выводим, что кратен 5, иначе нет
then
echo "divisible by 5" #Кратен 5
else
echo "ain't divisible by 5" #НЕ Кратен 5
fi
echo "Для выхода нажмите Ctrl+C"
done 
