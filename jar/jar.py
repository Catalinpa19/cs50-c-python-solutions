class Jar:
    def __init__(self, capacity=12):
        if capacity<0 or int(capacity)!=capacity:
            raise ValueError
        else:
            self._size=0
            self._capacity=capacity
    def __str__(self):
        return "🍪"*self._size

    def deposit(self, n):
        if n+self._size>self.capacity:
            raise ValueError
        else:
           self._size+=n

    def withdraw(self, n):
        if self._size<n:
               raise ValueError
        else:
            self._size-=n



    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
       return self._size


def main():
    jar=Jar()
    print(jar.capacity)
    jar.deposit(2)
    print(jar.size)
    jar.withdraw(1)
    print(jar.size)
    jar.deposit(20)


main()
