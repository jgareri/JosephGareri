//console.log('Beep Beep!');


const {Client, GatewayIntentBits, DiscordAPIError}=require('discord.js');

const{token}=require('./config.json');
//const openai = require('openai');
const client = new Client({ intents: [GatewayIntentBits.Guilds, GatewayIntentBits.GuildMessages, GatewayIntentBits.GuildPresences, GatewayIntentBits.MessageContent]});
client.login(token);
const request = require("request");
const async = require("async");
var accessToken = '';
client.on('ready', readyDiscord);
const fs = require("fs");
var CronJob = require('cron').CronJob;
const express = require('express');
const { ActivityType } = require('discord.js');
const plugEmoji = String.fromCodePoint(0x0001F50C);
require('dotenv').config();

//const OPENAI_API_KEY = 'chatgpt';

const { Configuration, OpenAIApi } = require('openai');
const configuration = new Configuration({
    organization: process.env.OPENAI_ORG,
    apiKey: process.env.OPENAI_KEY,
});
const openai = new OpenAIApi(configuration);


//let statusMessage = "The Matrix has you Neo";


const app = express();


function readyDiscord()
{
    console.log('ready');
    
}

client.once('ready', () =>
{
    console.log('Ready');
    console.log('JeeperBot is Online!');
    client.user.setActivity('for @JeeperBot',  {type: ActivityType.Watching} );
});

// client.on('interactionCreate', async interaction => 
// {
//     if(!interaction.isChatInputCommand()) return;

//     const {commandName} = interaction;

//     if (commandName === 'jeeperbot')
//     {
//         await interaction.reply('Bow down before the almighty... *cough*. Hey everyone, I am so happy to be finally be apart of the GGO Discord. Jeeper will hopefully make me more functional. Take care for now!');
        
//     }

// });


client.on('messageCreate', async function(message)
{
    
    if (message.author.bot) return;

    const botMention = message.mentions.users.find(user => user.id === '1007687409300946954');
    console.log(message.content, botMention);
     if (!botMention) return;

     //const input = message.content.replace('<@!${client.user.id}>', '').trim();

     //let conversationLog = [{role: 'system', content: "You are a friendly and helpful Discord chatbot. JeeperGary is your creator."}];

     //conversationLog.push({
       // role: 'user',
       // content: message.content,
    // })

     const response = await openai.createCompletion({
        model: "text-davinci-003",
        prompt: message.content,
        temperature: 0.9,
        max_tokens: 100,
       //n: 1,
        stop: ["JeeperBot:"],
     });

     //const output = response.data.choices[0].text;
     console.log(response.data.choices[0].text);
     message.reply(response.data.choices[0].text);
     return;
    console.log(response.content);
});


const config = JSON.parse(fs.readFileSync('./config.json'));
const port = config.port;
const endpoint = config.endpoint;

//assign the modules that we need for authentication and to get the data
const Stream = require("./getStreams.js");
const Auth = require("./auth.js");
const Channel = require("./channelData.js");

//define the api endpoint
app.get(endpoint, (req, res) => {
    const cachedData = fs.readFileSync('./cache.json');
    if (!cachedData) return;
    res.end(cachedData);
});

//listen on the defined port
app.listen(port, () => {
    UpdateAuthConfig();
    console.log(`app listening at http://localhost:${port}${endpoint}`);
});

//This is the function that will loop trough every streamer and push their data to the cache.json file
var Check = new CronJob(config.cron, async function () {
    const tempData = JSON.parse(fs.readFileSync('./config.json'));

    var cache = await Promise.all(tempData.channels.map(async function (chan, i) {
        var Channeldata = await Channel.getData(chan, tempData.twitch_clientID, tempData.authToken);
        var StreamData = await Stream.getData(chan, tempData.twitch_clientID, tempData.authToken);
        const url = `https://www.twitch.tv/${chan}`
        let returnData;

        //return error when the assigned streamer does not exist
        if (Channeldata == false) return {
            "streamerName": chan,
            "channelURL": url,
            "thumbnailURL":false,
            "title": false,
            "game": false,
            "viewers": false,
            "is_live": false,
            "startedAt": false,
            "language": false,
            "tags": [],
            "errors": [{ "error": "This user does not exist" }]
        };
        
        //this will run if the user is live
        if (StreamData.data.length > 0) {
            StreamData = StreamData.data[0]
            returnData = {
                "streamerName": StreamData.user_name,
                "channelURL": url,
                "thumbnailURL":Channeldata.thumbnail_url,
                "title": StreamData.title,
                "game": StreamData.game_name,
                "viewers": StreamData.viewer_count,
                "is_live": "online",
                "startedAt": StreamData.started_at,
                "language": StreamData.language,
                "tags": StreamData.tag_ids,
                "errors": []
            };
        } else {
            //else we return the normal channel data
            returnData = {
                "streamerName": Channeldata.display_name,
                "channelURL": url,
                "thumbnailURL":Channeldata.thumbnail_url,
                "title": Channeldata.title,
                "game": "unknown",
                "viewers": 0,
                "is_live": "offline",
                "startedAt": Channeldata.started_at,
                "language": Channeldata.broadcaster_language,
                "tags": Channeldata.tag_ids,
                "errors": []
            };
        };

        return returnData;
    }))

    //replace the old cache with the new data
    fs.writeFileSync('./cache.json', JSON.stringify(cache));
});

//update the authorization key every hour
var updateAuth = new CronJob('0 * * * *', async function () {
    UpdateAuthConfig();
});

//get a new authorization key and update the config
async function UpdateAuthConfig() {
    let tempData = JSON.parse(fs.readFileSync('./config.json'));

    //get the auth key
    const authKey = await Auth.getKey(tempData.twitch_clientID, tempData.twitch_secret);
    if (!authKey) return;

    //write the new auth key
    var tempConfig = JSON.parse(fs.readFileSync('./config.json'));
    tempConfig.authToken = authKey;
    fs.writeFileSync('./config.json', JSON.stringify(tempConfig));
}

updateAuth.start();
Check.start();

function gotMessage(msg){
    const channel = client.channels.cache.get('783075533080494131');
    channel.send('content');
    console.log(content);
    if(is_live === "online")
    {
        msg.send('Jeeper is live at https://www.twitch.tv/jeepergary');
    }
 }

// function channelRequest(accessToken){
//     setTimeout(() => {
//     const gameOptions = {
//         url: 'https://api.twitch.tv/helix/streams/user_id=531338528',
//         method: 'GET',
//         headers:{
//             'Client-ID': '7xefd8qcrnxjr4jr3bjibp0zws2yjt',
//             'Authorization': 'Bearer ' + accessToken
//         }
//     }
//     if(!accessToken){
//         console.log("No Token");
//     }else{
//         console.log(gameOptions);
    
//     const channelRequest = request.get(gameOptions,(err,res,body) => {
//         if(err){
//             return console.log(err);
//         }
        
//         console.log('Status: ${res.statusCode}');
//         console.log(JSON.parse(body));
//     });
    
//     };
    
//     },2000)
//     }
// const options = {
//     url: 'https://id.twitch.tv/oauth2/token',
//     json:true,
//     body: {
//     client_id: '7xefd8qcrnxjr4jr3bjibp0zws2yjt',
//     client_secret:'lu3t0zv18z6atyw3a3s6wnt7r6vbtv',
//     grant_type: 'client_credentials'
//     }
// };

// request.post(options, (err,res,body)=>{
//     if(err){
//         return console.log(err);
//     }
//     console.log('Status: ${res.statusCode}');
//     console.log(body.access_token);
//     channelRequest(body.access_token);
    
// });
// client.on('message', gotMessage);
 function gotMessage(msg){
    console.log(msg.content);
    if(msg.content === 'Jeeper Bot Speak')
    {
        msg.reply('Bow down before the almighty... *cough* Hey everyone, I am so happy to be finally be apart of the GGO Discord. Jeeper will hopefully make me more functional. Take care for now!');
    }
 }