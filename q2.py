arr_one = [1,4,5,7]
arr_two = [10,20,30,40]
sum = 0
x = 32
closest_below = list()
closest_above = list()
num_above = 0
num_below = 0

for i in range(0,len(arr_one)):
    for j in range(0,len(arr_two)):
        sum = arr_one[i]+arr_two[j]

        if sum==x : 
           print "The Closest Pair is Equal to",arr_one[i]," and ",arr_two[j]

	    elif sum<x: 
            closest_below.append(sum)

        else :
            closest_above.append(sum)


num_below = max(closest_below)
num_above = min(closest_above)


for i in range(0,len(arr_one)):
	for j in range(0,len(arr_two)):
        if arr_one[i]+arr_two[j] == num_below :
        	print "The Closest Pair Summing to ",x,"  below it is ",arr_one[i]," and ",arr_two[j]
				 
	
for i in range(0,len(arr_one)):
	for j in range(0,len(arr_two)):
        if arr_one[i]+arr_two[j] == num_above :
        	print "The Closest Pair Summing to ",x,"  above it is ",arr_one[i]," and ",arr_two[j]
				 
