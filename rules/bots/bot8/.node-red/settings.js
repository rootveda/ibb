module.exports = {
uiPort: process.env.PORT || 1588,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot8.json',
userDir: '/rules/bots/bot8/.node-red/',
nodesDir: '/rules/bots/bot8/.node-red/nodes',
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
httpNodeAuth: { user: "bot8", pass: "$2a$08$zuGWTw9Z9UlfM9g1KVcU5uIKQWEW7OoGjinOYHtdpCIPj/4tvfW6y" },
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

