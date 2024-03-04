# push_swap

The Push swap project entails a straightforward algorithmic task: sorting data.  
With a set of integer values, 2 stacks, and a series of instructions to manipulate the stacks, the objective is to develop a C program named push_swap. This program should efficiently compute and present on the standard output the shortest sequence of Push swap instructions required to sort the provided integers as arguments.

## Visualizer

https://github.com/ysengoku/42-push_swap/assets/130462445/1236213b-5ec4-482d-893f-a309f2b3240d  

https://github.com/o-reo/push_swap_visualizer  

  
## Authorized operations

- sa (swap a):  
	Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b):   
	Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss :  
	sa and sb at the same time.
  
- pa (push a):  
	Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. 
- pb (push b):  
  	 Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  
- ra (rotatea):  
	Shift up all elements of stack a by 1. The first element becomes the last one. 
- rb(rotateb):  
	Shift up all elements of stack b by 1. The first element becomes the last one. 
- rr :   
	ra and rb at the same time.
  
- rra (reverserotate a):  
	Shift down all elements of stack a by1. The last element becomes the first one. 
- rrb(reverserotate b):  
	Shift down all elements of stack b by1. The last element becomes the first one.  
- rrr :  
	rra and rrb at the same time.

## Algorithm
1. Check the syntax of arguments  
	examples of NG cases: `a` / `-` / `3+` / `-4-` / `2b` / `"123" 4 "-1 6" 0`  
	examples of OK cases: `12` / `+23` / `-34` / `03` / `-05` / `000` / `-0` / `+00`  
3. Check repeat
4. Initialize the stack a & check overflow/underflow (INT_MAX/INT_MIN)
5. Check if the stack a is already sorted
6. If not soerted, sort it
7. free stack a

### Check input arguments
#### Syntax check
##### In case of ac(argc) == 2
av(argv)[1] is a string with numbers and spaces

##### In case of ac(argc) > 2
Each av(argv)[i] except av[0] is a number

#### Repeat check

### Initialize stack a & check overflow/underflow  
1. Get numeric value with ft_atol
2. Check INT_MIN/INT_MAX
3. If OK --> append a node with int value to stack a
4. Continue until the end of av
5. Set index in ascending order (0 == min value)
6. If ac == 2, free av

### Sort
#### Small size stack (less than 21)

##### Three numbers
For the array {a, b, c}
I have to compare a & b / b & c / a & c
1. if 1st > 2nd --> swap 1st & 2nd (sa)
2. if 2nd > 3rd --> reverse rotate : 3rd, 1st, 2nd (rra)
3. if 1st > 3rd --> swap 1st & 2nd (sa)

##### Between 4 and 20 numbers
1. Find the smallest number
2. Move it to the top, then move it to stack b  
		Calculate the distace to top  
		Do 'ra' or 'rra' for needed times according to the distance  
		Do 'pb'  
4. Continue until the number of elements in stack a becomes 3.
5. 3. Do three numbers sort on stack a
6. Return all numbers in stack b to stack a

#### Larger size stack (greater than 20)
1. Get max number of bits  
	the greatest index = stack_size - 1  
	calculate the number of bits of the greatest index  
2. Sort nodes : 0-->b 1-->a  
	1st bit (from right)  
		From top, if 0 --> pb / if 1 --> ra  
		pa until stack b is empty  
	check if a is sorted & if not, repeat to the next bit  
 	---> Continue until the last bit (last = max number of bit)  

## Resources

### Tutorial
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

### Tester
https://github.com/SimonCROS/push_swap_tester
