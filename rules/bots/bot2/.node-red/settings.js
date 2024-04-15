module.exports = {
uiPort: process.env.PORT || 1582,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot2.json',
userDir: '/rules/bots/bot2/.node-red/',
nodesDir: '/rules/bots/bot2/.node-red/nodes',
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
httpNodeAuth: { user: "bot2", pass: "$2a$08$RAx/U35oWV5pWtpnB6jbfeGpHJasAX7B/fmssRNTOX8GBw9/vgTVq" },
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

