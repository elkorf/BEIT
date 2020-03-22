#!/bin/sh

createBook()
{
	echo ""	
   	echo "------------- Creating Address Book --------------"
	echo "Enter filename :\c"
	read fname
        if [ -e $fname ]						#to check file existance
        then echo "File already exists"
        else
            touch $fname     						#create file
            echo "------------------- Enter record ----------------"
	  	echo "\n Enter the Name - \c" 				# Validation for name
			while true	
			do 
				read nm
				len=$(echo -n $nm | wc -m)
				if test $len -eq 0; then
					echo "\n Name cannot be empty, Please enter the name again - \c"
					
				else
					break
				fi
			done
		
	  	echo "\n Enter the Address - \c"			# Validation for address
			while true
			do 
				read add
				len=$(echo -n $add | wc -m)
				if test $len -eq 0; then
					echo "\n Address cannot be empty, Please enter the address again - \c"
					
				else
					break
				fi
			done
		
	   	echo "\n Enter the City - \c"
			read city
		
	   	echo "\n Enter the Pin Number - \c"			# Validation for pin code
			while true
			do 
				read pin
				len=$(echo -n $pin| wc -m)
				if test $len -eq 6; then
					break
				else
					echo "\n Pin should have 6 digits, Please enter the Pin again - \c"
				fi
			done
	        
			
		echo "\n Enter the Phone Number - \c"			# Validation for phone number
			while true
			do 
				read phn
				len=$(echo -n $phn | wc -m)
				if test $len -eq 10; then
					break
				else
					echo "\n Phone should have 10 digits, Please enter the Phone again - \c"
				fi
			done
		
			
			echo "------------------------- Address Book --------------------------"
			echo "Name\t Address\t City \t\t PinCode\t Phone No\n" #Printing records in file
			echo "$nm \t $add \t $city \t\t $pin \t $phn " >> $fname
			cat $fname
			echo ""
			echo "File Created!"
		fi
       
	
		
		
}

insertBook()
{
 	echo ""
   	
   	echo "------------------ Inserting in Address Book ------------"
	echo "Enter how many records you want to insert :\c"
	read input
	while [ $input -ge 1 ]						#Inserting records
	do
		echo "------------------- Enter record ----------------"
	  	echo "\n Enter the Name - \c"				# Validation for name
			while true
			do 
				read nm
				if grep -q -w  $nm $fname
				then
					echo "\nRecord already exists !"
					break
				else
					break
				fi
			done
		
	 	 echo "\n Enter the Address - \c"			# Validation for address
			while true
			do 
				read add
				len=$(echo -n $add | wc -m)
				if test $len -eq 0; then
					echo "\n Address cannot be empty, Please enter the address again - \c"
					
				else
					break
				fi
			done
		
	  	 echo "\n Enter the City - \c"
			read city
		
	   	echo "\n Enter the Pin Number - \c"
			# Validation for pin code
			while true
			do 
				read pin
				len=$(echo -n $pin| wc -m)
				if test $len -eq 6; then
					break
				else
					echo "\n Pin should have 6 digits, Please enter the Pin again - \c"
				fi
			done
		echo "\n Enter the Phone Number - \c"
			# Validation for pin code
			while true
			do 
				read phn
				len=$(echo -n $phn| wc -m)
				if test $len -eq 10; then
					break
				else
					echo "\n Phone no should have 6 digits, Please enter the Pin again - \c"
				fi
			done
			echo "$nm \t $add \t $city \t\t $pin \t $phn " >> $fname
			
		input=$((input-1))
		
   done
	echo ""
	echo "------------------------- Address Book --------------------------"
	echo "Name\t Address\t City \t\t PinCode\t Phone No\n"  
	sort $fname
	echo "Records Inserted!"	
}

delBook()
{
	echo ""
        echo "------------------------- Deleting a Record ----------------------"
	echo "Enter name of Record to be deleted :\c"
	read abc
   	if grep -q -w $abc $fname
	then
		grep -v -i -w "$abc" $fname > assign12.txt
   	    mv assign12.txt $fname
   	    echo "Record Deleted!"
	else
   		echo "Record Not Found"
    fi
}

searchBook()
{
	echo ""
   
        echo "---------------------- Searching a record ----------------------"
	echo "\n1. By name\n2. By Mobile no.\nEnter your choice :\c"
	read abc
	if test $abc -eq 1;then 
		echo "Enter name to be searched :\c"
        else
 		echo "Enter mobile number to be searched :\c"
        fi
	
	read abc
	if grep -q -w  $abc $fname
	then
		echo ""
		echo "------------------------ Address Book --------------------------"
		echo "Name\t Address\t City \t\t PinCode\t Phone No\n"  
		grep -w $abc $fname
    	echo "Record Found!"
	else
   		echo "Record Not Found!"
    fi
}
viewBook()
{
	echo ""
   
	echo "------------------------ Address Book --------------------------"
	echo "Name\t Address\t City \t\t PinCode\t Phone No\n"  
	sort $fname
	#cat $fname;
}
modifyBook()
{
  	echo ""
    
	echo "-------------------- Modifying a record ------------------------"
	echo "Enter name to be modified :\c"
	
	read inputid
	 
    if grep -q ^$inputid $fname
	then
		grep -v -i "^$inputid" $fname > assign12.txt
   	    	mv assign12.txt $fname
   	   	echo "------------------- Enter record ----------------"
	  		echo "\n Enter the Name - \c"
			# Validation for name
			while true
			do 
				read nm
				len=$(echo -n $nm | wc -m)
				if test $len -eq 0; then
					echo "\n Name cannot be empty, Please enter the name again - \c"
					
				else
					break
				fi
			done
		
		 	echo "\n Enter the Address - \c"
			# Validation for address
			while true
			do 
				read add
				len=$(echo -n $add | wc -m)
				if test $len -eq 0; then
					echo "\n Address cannot be empty, Please enter the address again - \c"
					
				else
					break
				fi
			done
		
	   		echo "\n Enter the City - \c"
			read city
		
		  	echo "\n Enter the Pin Number - \c"
			# Validation for pin code
			while true
			do 
				read pin
				len=$(echo -n $pin| wc -m)
				if test $len -eq 6; then
					break
				else
					echo "\n Pin should have 6 digits, Please enter the Pin again - \c"
				fi
			done
		echo "\n Enter the Phone Number - \c"
			# Validation for pin code
			while true
			do 
				read phn
				len=$(echo -n $phn| wc -m)
				if test $len -eq 10; then
					break
				else
					echo "\n Phone no should have 6 digits, Please enter the Pin again - \c"
				fi
			done
			echo "$nm \t $add \t $city \t\t $pin \t $phn " >> $fname
		echo ""
   		echo "---------------------------------------------------------"
   		echo "Name\t Address\t City \t\t PinCode\t Phone No\n"  
		sort $fname
   	    echo "Record Modified!"
	else
   		echo "Record Not Found"
    fi
    
}

ch=0
while [ $ch != "7" ]
do
	echo "\n\n-------------- MENU ---------------\n|	1.Create address book     |\n|	2.View address book	  |\n|	3.Insert a record	  |\n|	4.Search a record 	  |\n|	5.Delete a record    	  |\n|	6.Modify a record         |\n|	7.Exit                    |\n----------------------------------"
	echo "Enter your choice :\c"
	read ch
	#echo "You entered $ch"
	case $ch in
		"1")createBook;;
		
		"2")viewBook;; 
	
		"3")insertBook;;
	
		"4")searchBook;;
			
		"5")delBook;;
					
		"6")modifyBook;;
			
		"7")exit;;
		
		*)echo "Invalid choice!!";;
	esac
done		
	
