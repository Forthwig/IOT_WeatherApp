import pymongo
from bson.json_util import dumps
import json

############################################################################################################################################################################################################################################

class MongoDB: #Définition de notre classe MongoDB
    """Classe définissant la connection et traitement des datas avec MONGODB"""

    def __init__(self,username="Th4nx",password="Admin"): #Notre méthode constructeur
        """Pour se connecter à MongoDb"""
        
        self.mongo = pymongo.MongoClient(f"mongodb+srv://{username}:{password}@th4nx-ynlsp.gcp.mongodb.net/test?retryWrites=true&w=majority", connect=False)

        self.db = pymongo.database.Database(self.mongo, 'IOT')
        self.col = pymongo.collection.Collection(self.db, 'Iot_Weather')



    def recupdata(self):
        """Récupère les datas du JSON et les mets dans des tableaux"""
        col_results = json.loads(dumps(self.col.find().limit(18).sort("time", -1)))
        temp = []
        humi = []
        
        for i in range(len(col_results)):
            try:
                temp.append(col_results[i]["temp"])
                humi.append(col_results[i]["humidity"]) 
            except:
                pass
            
        return temp,humi

    def senddata(self,data1,data2):
        """Envois les datas du Sigfox vers MongoDb"""
        new_data = {"temp" : data1,
                    "humidity": data2}
        self.col.insert_one(new_data)
        
        
                

############################################################################################################################################################################################################################################  

myConnexion = MongoDB()

#print("J'ai",col.count_documents({}),"fichiers dans ma bdd")

#new_data= {  ##Add une data à la bdd 
#
#   'date' : '12/02/2020',
#    'temp' : 23,
#    'humidity': 72
#    }
#col.insert_one(new_data)

temp,hum = myConnexion.recupdata()
print("temp = ",temp)
print("hum = ",hum)
