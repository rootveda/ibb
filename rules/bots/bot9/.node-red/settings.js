module.exports = {
uiPort: process.env.PORT || 1589,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot9.json',
userDir: '/rules/bots/bot9/.node-red/',
nodesDir: '/rules/bots/bot9/.node-red/nodes',
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
httpNodeAuth: { user: "bot9", pass: "$2a$08$aMrAJPUJ9kYO2tHrE7CLFuAYu.uemOrXh3Z0M9imKjVp.cIQT5P1G" },
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

