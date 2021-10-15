import styled from "styled-components";
import City from "./Components/City";
import Weather from "./Components/Weather";
import { useState } from "react";
import Axios from "axios";
import {body} from "./index.css"

// const Container=styled.div`
//   display:flex;
//   flex-direction:column;
//   align-items:center;
//   width:380px;
//   padding:2px 10px;
//   margin:auto;
//   box-shadow:0 5px 6px 5px #091353;
//   border-radius:8px;
//   background:white;
//   border:#091353 solid 3.5px;
//   font-family:Montserrat;
//   background:#FFF5EB;
// `;
const Container=styled.div`
  display:flex;
   flex-direction:column;
   align-items:center;
   width:380px;
   padding:2px 10px;
   margin:auto;
   box-shadow:0 5px 6px 5px #091353;
   border-radius:8px;
   background:white;
   border:#091353 solid 3.5px;
   font-family:Montserrat;
   background:#FFF5EB;
`;
const AppLabel=styled.div`
  color:#A12568;
  margin:20px auto;
  font-size:30px;
  font-weight:bold;
  font-family:'Courier New', Courier, monospace;
`;
function App() {
  const [city, setcity] = useState();
  const [weather, setWeather] = useState();
  const fetchweather=async (e)=>{
    e.preventDefault();
    const responce=await Axios.get(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=fe4feefa8543e06d4f3c66d92c61b69c`);
    setWeather(responce.data);
  }; 
  return (
    <Container className="body">
        <AppLabel>Weather Today..</AppLabel>
        {city && weather ? (<Weather weather={weather} city={city}/>):(<City setcity={setcity} fetchweather={fetchweather}/>)}
    </Container>
  );
}

export default App;
