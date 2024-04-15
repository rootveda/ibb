module.exports = {
uiPort: process.env.PORT || 1590,
mqttReconnectTime: 15000,
serialReconnectTime: 15000,
debugMaxLength: 1000,
flowFile: 'flows_bot10.json',
userDir: '/rules/bots/bot10/.node-red/',
nodesDir: '/rules/bots/bot10/.node-red/nodes',
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
httpNodeAuth: { user: "bot10", pass: "$2a$08$MpqCIXKImEgyRN/sRbkpdexgFIsGoY0xQ1gdKUPrABtwFHBGknUtq" },
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

