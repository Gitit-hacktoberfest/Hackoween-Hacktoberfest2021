import styled from "styled-components"
export const WeatherInfoIcons = {
    sunset: "./icons/temp.svg",
    sunrise: "./icons/temp.svg",
    humidity: "./icons/humidity.svg",
    wind: "./icons/wind.svg",
    pressure: "./icons/pressure.svg",
};
export const WeatherIcons = {
    "01d": "./icons/sunny.svg",
    "01n": "./icons/night.svg",
    "02d": "./icons/day.svg",
    "02n": "./icons/cloudy-night.svg",
    "03d": "./icons/cloudy.svg",
    "03n": "./icons/cloudy.svg",
    "04d": "./icons/perfect-day.svg",
    "04n": "./icons/cloudy-night.svg",
    "09d": "./icons/rain.svg",
    "09n": "./icons/rain-night.svg",
    "10d": "./icons/rain.svg",
    "10n": "./icons/rain-night.svg",
    "11d": "./icons/storm.svg",
    "11n": "./icons/storm.svg",
    "13d":"./icons/13d@2x.png",
    "13n":"./icons/13n@2x.png",
    "50d":"./icons/50d@2x.png",
    "50n":"./icons/50n@2x.png",
  };
const WeatherCondition=styled.div`
    display:flex;
    flex-direction:column;
    align-items:center;
    width:100%;
    justify-content:space-evenly;
    margin:30px auto;
`
const WeatherLogo=styled.img`
    width:140px;
    height:140px;
    margin:15px auto;

`
const Condition=styled.span`
   margin: 20px auto;
    text-transform: capitalize;
    font-size: 18px;
    & span {
        font-size: 28px;
    }
    font-family:Arial, Helvetica, sans-serif;
`
const Location=styled.span`
    margin: 15px auto;
    text-transform: capitalize;
    font-size: 28px;
    font-weight: bold;
    font-family:'Courier New', Courier, monospace;
`
const WeatherInfoLabel=styled.span`
    margin: 20px 25px 10px;
    text-transform: capitalize;
    text-align: start;
    width: 90%;
    font-weight: bold;
    font-size: 19px;
    font-family:Arial, Helvetica, sans-serif;
`
const WeatherInfoContainer=styled.div`
    display: flex;
    width: 90%;
    flex-direction: row;
    justify-content: space-evenly;
    align-items: center;
    flex-wrap: wrap;
`
const InfoIcon = styled.img`
  width: 36px;
  height: 36px;
`
const InfoLabel = styled.span`
  display: flex;
  flex-direction: column;
  font-size: 14px;
  margin: 15px;
  & span {
    font-size: 12px;
    text-transform: capitalize;
  }
`;
const InfoContainer = styled.div`
  display: flex;
  margin: 5px 10px;
  flex-direction: row;
  justify-content: space-evenly;
  align-items: center;
`;
const Other=styled.div`
    display:flex;
    margin:5px 10px;
    flex-direction:row;
    justify-content:space-evenly;
    align-items:center;
    font-family:'Courier New', Courier, monospace;
    font-weight:bold;
`
const WeatherInfoComponent=(props)=>{
    const {name,value}=props;
    return (
        <InfoContainer>
            <InfoIcon src={WeatherInfoIcons[name]}/>
            <InfoLabel>
                {value}
                <span>{name}</span>
            </InfoLabel>
        </InfoContainer>
    )
}
const Weather=(props)=>
{
    const {weather}=props;
    const isDay = weather?.weather[0].icon?.includes('d')
    const getTime = (timeStamp) => {
        return `${new Date(timeStamp * 1000).getHours()} : ${new Date(timeStamp * 1000).getMinutes()}`
    }
    console.log(weather?.weather[0]?.icon);
    return (
        <>
        <WeatherCondition>
            <Condition><span>{`${Math.floor(weather?.main?.temp - 273)}°C`}</span>{`  |  ${weather?.weather[0].description}`}</Condition>
            <Other>Feels Link:
            {Math.floor(weather?.main?.feels_like - 273)}°C
                Visibility:
                {(weather?.visibility)/1000} Km
            </Other>
            <WeatherLogo src={WeatherIcons[weather?.weather[0].icon]}/>
            <Location>{`${weather?.name} ${weather?.sys?.country}`}</Location>
            <WeatherInfoLabel>Weather Info</WeatherInfoLabel>
            <WeatherInfoContainer>
                <WeatherInfoComponent name={isDay ? "sunset" : "sunrise"} value={`${getTime(weather?.sys[isDay ? "sunset" : "sunrise"])}`}/>
                <WeatherInfoComponent name="humidity" value={weather?.main?.humidity}/>
                <WeatherInfoComponent name="wind" value={weather?.wind.speed}/>
                <WeatherInfoComponent name="pressure" value={weather?.main?.pressure}/>
            </WeatherInfoContainer>
        </WeatherCondition>
        </>
    )
}
export default Weather;
