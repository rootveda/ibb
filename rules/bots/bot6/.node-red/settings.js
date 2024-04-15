module.exports = {
uiPort: process.env.PORT || 1586,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot6.json',
userDir: '/rules/bots/bot6/.node-red/',
nodesDir: '/rules/bots/bot6/.node-red/nodes',
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
httpNodeAuth: { user: "bot6", pass: "$2a$08$LJ5RAQ8Ik4JLQrpJ.mEkHOQuwsqYA0qJmlYx6BKRzeBwiCANRTtNu" },
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

