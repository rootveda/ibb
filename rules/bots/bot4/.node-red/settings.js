module.exports = {
uiPort: process.env.PORT || 1584,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot4.json',
userDir: '/rules/bots/bot4/.node-red/',
nodesDir: '/rules/bots/bot4/.node-red/nodes',
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
httpNodeAuth: { user: "bot4", pass: "$2a$08$Pd7Ty45NjfguRmHp0PT0jOKpNFxGKyseYEk53ui1kamy6zKbfFtl." },
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

