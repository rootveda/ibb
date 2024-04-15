module.exports = {
uiPort: process.env.PORT || 1580,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_main.json',
userDir: '/rules/bots/main/.node-red/',
nodesDir: '/rules/bots/main/.node-red/nodes',
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
//httpNodeAuth: { user: "bot1", pass: "$2b$08$2TLAT0Bo8dqscbt0/kAyX.x.ZMaJXny1VvJIksXDNRzcjtrlFIwKS" },
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

