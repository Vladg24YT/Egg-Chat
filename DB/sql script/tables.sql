create table user
(
	id int primary key,
	login varchar(20),
	password varchar(20)
	Sock_desc
);
create table chats
(
	id int primary key,
	chat_name varchar(30),
	users_id
);
create table messages
(
	id_chat foreign key references chat(id),
	sender foreign key references user(id),
	message_text text,
	send_time timestamp
)
