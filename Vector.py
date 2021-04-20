# In this python file, only the definations for the magic functions and the basic operations
# for the question segments are provided. There may be the need to add new functions or overload 
# existing ones as per the question requirements.


#19CS10031
#Abhishek Gandhi
#AssignmentQ1
#Data Science Assignment

class Vector:
        
    def __init__(self, *args): 

        # if arg is an int(dimension)
        temp=args[0]
        if isinstance(temp, int): 
            self._coords = [0]*temp
        elif not isinstance(temp, list):
            try:
                temp = list(temp)
            except:
                print("Invalid input")
        if isinstance(temp, list):
            self._coords = temp

    def __len__(self):
        return len(self._coords)
        # return the dimension of the vector

    def __getitem__(self, j):
        if j<self.__len__():
            return self._coords[j]
        else:
            return None
        # return the jth coordinate of the vector

    def __setitem__(self, j, val):
        if j<self.__len__():
            self._coords[j]=val
        else:
            print("Invalid j, j must be less than ",self.__len__())
        # set the jth coordinate of vector to val

    def __add__(self, other):
        if(self.__len__()==len(other)):
            v = Vector(self.__len__())
            for i in range(self.__len__()):
                v[i] = self.__getitem__(i)+other[i]
            return v
        print("Invalid Addition")
        return None
        # u + v
            
    def __eq__(self, other):
        if(self.__len__()==len(other)):
            for i in range(len(other)):
                if self.__getitem__(i)!=other[i]:
                    return False
            return True
        return False
        # return True if vector has same coordinates as other
    
    def __ne__(self, other):
        return not self.__eq__(other)
        # return True if vector differs from other
    
    def __str__(self):
        s = '<'
        for i in range(self.__len__()):
            s+=str(self.__getitem__(i))
            if i!= self.__len__()-1:
                s+=', '
        s+='>'
        return s

        # return the string representation of a vector within <>

    def __sub__(self, other):
        return  self.__add__(-other)
        # Soln for Qs. 2
    
    def __neg__(self):
        v = Vector(self.__len__())
        for i in range(self.__len__()):
            v[i]= self.__getitem__(i)*-1
        return v
        # Soln for Qs. 3
    
    def __rmul__(self, value):
        return (self * value) 
    
    def __mul__(self, other):
        if isinstance(other, int):
            v = Vector(self.__len__())
            for i in range(self.__len__()):
                v[i] = self.__getitem__(i)*other
            return v
        if isinstance(other, Vector):
            if len(other)==self.__len__():
                value=0
                for i in range(self.__len__()):
                    value = other[i]*self.__getitem__(i)
                return value
        return None
        # Soln for Qs. 4, 5 and 6
    
def main():
    v1 = Vector(5)
    v2 = Vector (7)
    v3 = Vector([1,2,3,4,5])
    v4 = Vector((1,2,3))
 
    print("v1=",v1)
    print("v3=",v3)
    print("v2=",v2)
    print("v4=",v4)

    print("length of v2: ",len(v2))
    v4=v1+v3
    print("v4=v1+v3=",v4)
    print("v4==v3: ",v4==v3)
    print("v4==v1: ",v4==v1)
    v5=-v3
    print("v5=-v3: ",v5)
    v6=v3-v5
    print("v6=v3-v5=",v6)
    v7 = 3*v6
    v8 = v6*3
    v9 = v6*v3
    print("v7=3*v6=",v7)
    print("v8=v6*3=",v8)
    print("v9=v6*v3=",v9)
    print("v6!=v3",v6!=v3)

    # Add suitable print statements to display the results
    # of the different question segments


if __name__ == '__main__':
    main()