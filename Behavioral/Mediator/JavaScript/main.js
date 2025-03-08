// main.js

const ChatMediator = require("./chatMediator");
const ChatUser = require("./chatUser");

const chatMediator = new ChatMediator();

const user1 = new ChatUser(chatMediator, "Alice");
const user2 = new ChatUser(chatMediator, "Bob");
const user3 = new ChatUser(chatMediator, "Charlie");

chatMediator.addUser(user1);
chatMediator.addUser(user2);
chatMediator.addUser(user3);

user1.sendMessage("Hello, everyone!");
user2.sendMessage("Hey Alice!");
