#!/usr/bin/node

const request = require('request');
const FILMID = process.argv[2];

const URL_BASE = 'https://swapi-api.hbtn.io/api/films';

function doRequest (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (error, res, body) {
      if (!error && res.statusCode === 200) {
        resolve(JSON.parse(body));
      } else {
        reject(error);
      }
    });
  });
}

async function main (filmID) {
  const filmId = await doRequest(`${URL_BASE}/${filmID}`);
  for (const n of filmId.characters) {
    const person = await doRequest(n);
    console.log(person.name);
  }
}

main(FILMID);