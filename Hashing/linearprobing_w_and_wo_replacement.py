#-1 if slot is empty, -2 is slot is deleted

class Hashing:
    def hash(self,tno):
        return (tno%n)
class PhoneBook:
    def __init__(self,n):
        self.size=0
        self.list1=[-1]*n   #making every element of the list = -1
        
        self.size2=0
        self.list2=[-1]*n   

    def woinsert(self):
        tno=int(input("Enter the telephone number to be inserted"))
        h=Hashing()
        i=h.hash(tno)
        if(self.size==n):
            print('Array full')
            return
            

        while(self.list1[i]!=-1 and self.list1[i]!=-2 and self.list1[i]!=tno):
            i=(i+1)%n
        if self.list1[i]==tno:
            print('Duplicates not permitted')
            return
            
        else:
            self.list1[i]=tno
            self.size+=1

    def wodisplay(self):
        for i in range(0,n):
            print(self.list1[i])

    def wosearch(self):
        key=int(input("Enter the number you are searching for:"))
        h1=Hashing()
        h=h1.hash(key)
        i=h
        wocount=0
        
        while(self.list1[i]!=-1):
            wocount+=1
            if(self.list1[i]==key):
                print('Key found')
                print("No of comparisons:",wocount)
                return
            i=(i+1)%n
            if(i==h):   #after you traverse the entire list and return to the same position
                print('Key not found')
                return
        print('Not found')
        print("No of comparisons:",wocount)
    
    def wodelete(self):
        key=int(input("Enter the number you want to delete:"))
        h1=Hashing()
        h=h1.hash(key)
        i=h

        while(self.list1[i]!=-1):
            if(self.list1[i]==key):
                print('Key found and deleted:', key)
                self.list1[i]=-2
                self.size-=1
                return
            i=(i+1)%n
            if(i==h):   #after you traverse the entire list and return to the same position
                print('Key to be deleted not found')
                return
        print('Key to be deleted not found')

    
    def winsert(self):
        tno=int(input("Enter the telephone number to be inserted"))
        h=Hashing()
        i=h.hash(tno)
        if(self.size2==n):
            print('Array full')
            return
        
        if(self.list2[i]=='1'or self.list2[i]==-2):
            self.list2[i]=tno
        
        else:
            temp=self.list2[i]
            if(temp%n==tno%n):
                temp=tno
                while(self.list2[i]!=-1 and self.list2[i]!=-2 and self.list2[i]!=tno):
                    i=(i+1)%n
                if self.list2[i]==tno:
                    print('Duplicates not permitted')
                    return
            
                else:
                    self.list2[i]=tno 
                    self.size2+=1

            else:
                self.list2[i]=tno
                i+=1
                while(self.list2[i]!=-1 and self.list2[i]!=-2 and self.list2[i]!=tno):
                    i=(i+1)%n
                
                self.list2[i]=temp
                self.size2+=1
    
    def wdisplay(self):
        for i in range(0,n):
            print(self.list2[i])

    def wsearch(self):
        key2=int(input("Enter the number you are searching for:"))
        h1=Hashing()
        h=h1.hash(key2)
        i=h
        wcount=0

        while(self.list2[i]!=-1):
            wcount+=1
            if(self.list2[i]==key2):
                print('Key found')
                print("No of comparisons:",wcount)
                return
            i=(i+1)%n
            if(i==h):   #after you traverse the entire list and return to the same position
                print('Key not found')
                return
        print('Not found')
        print("No of comparisons:",wcount)

    def wdelete(self):
        key2=int(input("Enter the number you want to delete:"))
        h1=Hashing()
        h=h1.hash(key2)
        i=h

        while(self.list2[i]!=-1):
            if(self.list2[i]==key2):
                print('Key found and deleted:', key2)
                self.list2[i]=-2
                self.size2-=1
                return
            i=(i+1)%n
            if(i==h):   #after you traverse the entire list and return to the same position
                print('Key to be deleted not found')
                return
        print('Key to be deleted not found')


    

    

n=int(input("Enter the total number of records"))
p=PhoneBook(n)

ans=int(input("With(0) or without replacement?(1)"))

if(ans==1):
    #without replacement menu
    while (True):
        print('WITHOUT REPLACEMENT Menu:\n 1.Insert\n 2.Search\n 3.Delete\n 4.Display\n 5.Exit')
        choice=int(input('Enter choice:'))
        if(choice==1):
            p.woinsert()
        elif(choice==2):
            p.wosearch()
        elif(choice==3):
            p.wodelete()
        elif(choice==4):
            p.wodisplay()
        elif(choice==5):
            break
if(ans==0):
    #with replacement menu
    while (True):
        print('WITH REPLACEMENT Menu:\n 1.Insert\n 2.Search\n 3.Delete\n 4.Display\n 5.Exit')
        choice=int(input('Enter choice:'))
        if(choice==1):
            p.winsert()
        elif(choice==2):
            p.wsearch()
        elif(choice==3):
            p.wdelete()
        elif(choice==4):
            p.wdisplay()
        elif(choice==5):
            break



        