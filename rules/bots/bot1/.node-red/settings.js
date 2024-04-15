module.exports = {
uiPort: process.env.PORT || 1581,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot1.json',
userDir: '/rules/bots/bot1/.node-red/',
nodesDir: '/rules/bots/bot1/.node-red/nodes',
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
httpNodeAuth: { user: "bot1", pass: "$2a$08$eUwd9TCKdDMomLKWpLXzz.OcwVAY4XONMO/./UJ.SWB6LCKNGnpZi" },
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

