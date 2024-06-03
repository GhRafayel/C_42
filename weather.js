const weather_form = document.getElementById('weater_form');
const weater_root  = document.getElementById('weater_root');
const weather_celsius = document.getElementById('weather_celsius');
const weather_wind = document.getElementById('weather_wind');
const weather_minTemp = document.getElementById('weather_minTemp');
const weather_maxTemp = document.getElementById('weather_maxTemp');
const weather_video = document.getElementById('weather_video');
let weather_data = {};
let stInterval;
weather_response(document.getElementById('weather_input').value);

weather_form.addEventListener('submit',(e)=> {
  e.preventDefault();
  weather_response(e.target[0].value);
});

function weather_response(name){
  
  fetch(`https://api.openweathermap.org/data/2.5/forecast?q=${name}&appid=8109965e7254a469d08a746e8b210e1e&units=imperial&cnt=10`)
  .then(strim => strim.json())
  .then(res =>  weather_distract(res))
  .catch(error =>  console.log(error , 'something problem'));
}

function weather_distract(res){
  weather_data =  {
    ...res.list[0].weather[0],
    ...res.list[0].main,
    ...res.list[0].wind,
    value: ["\u2109","\xB0C","\u212A"],
    index: 0,
  }
  weather_HTML_innerText(weather_data);
  res.list[0].weather[0].main === "Rain"  ? weather_video.src = '/video/raining.mp4' : 
  res.list[0].weather[0].main === "Clouds" ? weather_video.src = '/video/weather.mp4' : weather_video.src = '/video/sunny.mp4' 
  console.log(res.list[0].weather[0].main)
}

function weather_HTML_innerText(weather){
  if(weather.index === 1 ){
    weather_celsius.innerText = weather_fahrenheit_to_celsius(weather.temp) + weather.value[weather.index]
    weather_minTemp.innerText = weather_fahrenheit_to_celsius(weather.temp_min) + weather.value[weather.index]
    weather_maxTemp.innerText = weather_fahrenheit_to_celsius(weather.temp_max) + weather.value[weather.index]
    weather_wind.innerText = Math.floor(weather.speed * 1.609344)+ "km";
  }else if(weather_data.index === 2){
    weather_celsius.innerText = weather_fahrenheit_to_Kelvin(weather.temp) + weather.value[weather.index]
    weather_minTemp.innerText = weather_fahrenheit_to_Kelvin(weather.temp_min) + weather.value[weather.index]
    weather_maxTemp.innerText = weather_fahrenheit_to_Kelvin(weather.temp_max) + weather.value[weather.index]
    weather_wind.innerText = Math.floor(weather.speed * 1.609344)+ "km";
  }else{
    weather_celsius.innerText = weather.temp + weather.value[weather.index]
    weather_wind.innerText = weather.speed + "m";
    weather_minTemp.innerText = weather.temp_min + weather.value[weather.index]
    weather_maxTemp.innerText = weather.temp_max +weather.value[weather.index]
  }
}

stInterval = setInterval(()=>{
  weather_data.index += 1;
  if(weather_data.index > 2)  weather_data.index = 0;
  weather_HTML_innerText(weather_data);
 
},5000);

function weather_fahrenheit_to_celsius(namber){
  return Math.ceil( (namber - 32) * 5/9 );

}

function weather_fahrenheit_to_Kelvin(number){
    return Math.floor( (number - 32) * 5 / 9 + 273.15 )
}

   
    





      