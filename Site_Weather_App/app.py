############# FLASK IMPORT ######################
from flask import Flask
from flask import render_template
from datetime import time
from flask import request
from flask import jsonify

###########IMPORT OF BDD CLASS ##################
from MongoDB_Connection import MongoDB
from Conver import Convertion





app = Flask(__name__)


@app.route("/", methods=['POST'])
def data():
        
	body = request.json
	myConnexion = MongoDB()
	conv = Convertion()
	if body == None:
		return "not a json"
	if 'data' in body.keys():
		print("la data est", body['data'])
		tt,hh = conv.convert(body['data'])
		myConnexion.senddata(hh,tt)
		print("data send")
	return jsonify(body)

@app.route("/")
def index():
    myConnexion = MongoDB()
    temperatures,humidity = myConnexion.recupdata()
    long = len(temperatures)-1
    return render_template("index.html",messaget = "Ma température :",messageh = "Mon humiditée :",temp =temperatures[long], humi=humidity[long])

@app.route("/line_chart")
def line_chart():
    legend = 'Temperatures'
    legend2 = 'Humidity'

    myConnexion = MongoDB()
    temperatures,humidity = myConnexion.recupdata()
    times = ['12:00PM', '12:10PM', '12:20PM', '12:30PM', '12:40PM', '12:50PM',
             '1:00PM', '1:10PM', '1:20PM', '1:30PM', '1:40PM', '1:50PM',
             '2:00PM', '2:10PM', '2:20PM', '2:30PM', '2:40PM', '2:50PM']
    return render_template('line_chart.html', values=temperatures,valuees = humidity, labels=times, legend=legend, legend2=legend2)




if __name__ == "__main__":
    app.run(debug=True)
