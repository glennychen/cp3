import time
counter = 0
ultimate_count = 1
while True:
    if ultimate_count == 4:
        print("Use 4 ultimates")
        break
    counter +=1
    print(counter )
    time.sleep(1)
    if counter%54 == 0:
        print("Heal")
    if counter%56 == 0:
        ultimate_count += 1
        print("ULTIMATE:"+ str(ultimate_count))
        counter = 0
        
