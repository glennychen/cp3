import time
counter = 0
ultimate_count = 1
while True:
    if ultimate_count == 4:
        print("Use 4 ultimates")
        break
    time.sleep(1)
    counter +=1
    print(counter)
    if counter%54 == 0:
        print("Heal")
    if counter%56 == 0:
        print("ULTIMATE:"+ str(ultimate_count))
        print('\a')
        ultimate_count += 1
        counter = 0
        
