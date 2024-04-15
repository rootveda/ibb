module.exports = {
uiPort: process.env.PORT || 1585,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot5.json',
userDir: '/rules/bots/bot5/.node-red/',
nodesDir: '/rules/bots/bot5/.node-red/nodes',
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
httpNodeAuth: { user: "bot5", pass: "$2a$08$eoIhdT8gdvX7exBRcfxtNeMvwqNNu1XAk4mR2tMRm9J4mBeq/QvXW" },
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

