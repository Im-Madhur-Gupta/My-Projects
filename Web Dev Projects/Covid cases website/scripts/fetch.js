// I have used fetch api, called node-fetch (npm install node-fetch, sirf node ke liye hi install karna padega in-browser to pehle se hi padi he)
// const fetch = require("node-fetch");

// Tips -
// 1. In-browser JS me require() chalwane ke liye mujhe RequireJS ka use karna padega.
// 2. fs is a NodeJS module it won't work for in-browser JS due to security reasons, for that purpose we have localStorage ye temporarily data browser me store karwa deta he.

function updateMap() {
    fetch("https://disease.sh/v3/covid-19/countries")
        .then(response => response.json())
        .then(dataArr => {
            dataArr.forEach(element => {
                let long = element.countryInfo.long;
                let lat = element.countryInfo.lat;

                todayCases = element.todayCases;
                if (todayCases > 20) {
                    color = "rgb(255,0,0)";
                }
                else if (todayCases == 0) {
                    color = "rgb(124,252,0)"
                }
                else if (todayCases > 0 && todayCases <= 20) {
                    color = "rgb(255, 165, 0)"
                }

                // Mark on the map
                new mapboxgl.Marker({
                    draggable: false,
                    color: color
                }).setLngLat([long, lat]).addTo(map);
            });
        });

}
updateMap();