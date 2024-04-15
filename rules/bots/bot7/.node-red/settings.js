module.exports = {
uiPort: process.env.PORT || 1587,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot7.json',
userDir: '/rules/bots/bot7/.node-red/',
nodesDir: '/rules/bots/bot7/.node-red/nodes',
adminAuth: {
type: "credentials",
users: [
  {
       username: "ibbroothere",
        password: "$2b$08$IWR/p.zn8QxfpYjNVSIm9.E/Wg/9VUmeRtRGaWJ3V8lYGQcxPSnxW",
         permissions: "*"
      }
   ]
},
httpNodeAuth: { user: "bot7", pass: "$2a$08$RPxiBVfv5RV/4J3s6CCNU.XIQgsK29yUOoH7KHh6g1cAIWnIPdCsm" },
functionGlobalContext: {
},
logging: {
console: {
    level: "info",
     metrics: false,
      audit: false
   }
}
}

