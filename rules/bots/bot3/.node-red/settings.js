module.exports = {
uiPort: process.env.PORT || 1583,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot3.json',
userDir: '/rules/bots/bot3/.node-red/',
nodesDir: '/rules/bots/bot3/.node-red/nodes',
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
httpNodeAuth: { user: "bot3", pass: "$2a$08$Qn9QrdZ5NwvwMmtp8vtxN.0b98wbB93x75neM5mBVZe/SprLA0kNC" },
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

