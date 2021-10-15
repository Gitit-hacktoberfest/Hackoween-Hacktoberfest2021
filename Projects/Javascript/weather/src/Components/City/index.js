import styled from "styled-components"
import {FcSearch} from "react-icons/fc"

const WeatherLogo=styled.img`
    width:140px;
    height:140px;
    margin:40px auto;

`
const Text=styled.span`
    color:black;
    font-size:18px;
    font-weight:bold;
    margin:10px auto;
    font-family:'Courier New', Courier, monospace;
`
const SearchBox=styled.form`
    display:flex;
    flex-direction:row;
    color:black;
    border:black solid 3.5px;
    border-radius:5px;
    font-size:18px;
    font-weight:bold;
    margin:20px auto;
    font-family:'Courier New', Courier, monospace;
    & input{
        padding:10px;
        font-size:15px;
        border:none;
        outline:none;
        background-color:#FFF5EB;
    }
`
const style={cursor:"pointer"}
function City(props)
{
    const {setcity,fetchweather}=props;
    return (
        <>
        <WeatherLogo src={"/icons/perfect-day.svg"}/>
        <Text>Find the Weather of your City</Text>
        <SearchBox onSubmit={fetchweather}>
            <input placeholder="Your City" onChange={(e)=>setcity(e.target.value)}/>
            <FcSearch size="2.5em" style={style} type={"submit"}/>
        </SearchBox>
        </>
    )
}
export default City;
