import paho.mqtt.client as mqtt


TOPIC = "home42/bedroom/light"      #Your Topic to publish
MQTT_BROKER = "broker.hivemq.com"   #Server address
PORT = 1883
QOS = 1 #Quality of Service : Level At most once (0) , At least once (1) ,Exactly once (2)

client = mqtt.Client()

client.connect(MQTT_BROKER,PORT) #connect to Broker
print("Connect to Broker: {}".format(MQTT_BROKER))

data="ON"  #Mesasage to Topic
client.publish(TOPIC,data) #send Data



