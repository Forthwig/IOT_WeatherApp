
// De ce que j'ai compris vite tef, ca c'est une vue JS associé à un élement
var weather = new Vue({
    el: '#weather',
    
    data: {
        dataWeather: []
    },
    
    mounted: function () {
        this.getDataWeather('Paris');
    },        
    
    methods: {
        getDataWeather: function (ville) {
            this.$http.get(`https://api.openweathermap.org/data/2.5/weather?q=${ ville }&APPID=82c361ad90bd436e730f26c8f5af0f26&units=metric&lang=fr`)
            .then(response => {
                this.dataWeather = response.data
            })
        }
    }
    
});

var ville = new Vue({
    el: '#mySidenav',
    
    data: {},   
    
    methods: {
        changeCity: function (event) {
            //recupere la valeur de la balise qu'on vient de cliquer
            weather.getDataWeather(event.srcElement.text);
            
        }
    }
    
});
