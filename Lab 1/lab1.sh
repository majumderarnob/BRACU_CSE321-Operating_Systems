a)
$cat > 20301089_1.txt
$cat > 20301089_2.txt
$cat > 20301089_3.txt
$cat > 20301089_4.txt

$mkdir Arnob1
$mkdir Arnob2

$mv 20301089_1.txt 20301089_2.txt 20301089_3.txt Arnob1

$cp 20301089_1.txt 20301089_2.txt Arnob2

$mkdir Arnob3
$cp -r Arnob1 Arnob3
$cd Arnob3
$ls -l 
$chmod g=rx Arnob3
$chmod o=rx Arnob3
$cd Arnob3
$pwd
$ls

$mv Arnob3 root

$rm -r *

b)
$grep -o CSE course.txt|wc -l

c)
$ls-l

d)
$head -17 line.txt| tail -5

