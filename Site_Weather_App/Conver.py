class Convertion:
    def __init__(self):
        self.data = []
          
        
        

    def convert(self, data):
        temp=int(data[0])*(16**1)+ int(data[1])*(16**0)
        humi=int(data[2])*(16**1)+ int(data[3])*(16**0)

        return temp, humi


#c="2514000000"



        
#myConnexion = Convertion()
#b,d = myConnexion.convert(c)
#print("La température est de",d)
#print(type(b))
#print("L'humiditée est de",b)
#print(type(b))



