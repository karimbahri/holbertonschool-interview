#!/usr/bin/node
'use strict';
const request = require('request');

const getCharacterName = (url) => {
  return new Promise((resolve, reject) => {
    request(url, (err, res, body) => {
      if (err) {
        reject(err);
      } else { resolve(JSON.parse(body).name); }
    });
  });
};

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`, async (err, res, body) => {
  if (err) {
    console.error(err);
    return;
  }
  const charactersAPI = JSON.parse(body).characters;
  const characters = [];
  for (let key in charactersAPI) {
    characters.push(await getCharacterName(charactersAPI[key]));
  }
  for (const element of characters) {
    console.log(element);
  }
});
