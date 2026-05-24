// sw.js – Service Worker for SA-AKHRAN PWA

const CACHE_NAME = 'sa-akhran-v1';
const urlsToCache = [
  '/SA-AKHRAN-V1-/',
  '/SA-AKHRAN-V1-/index.html',
  '/SA-AKHRAN-V1-/manifest.json'
];

self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(CACHE_NAME)
      .then(cache => cache.addAll(urlsToCache))
  );
});

self.addEventListener('fetch', event => {
  event.respondWith(
    caches.match(event.request)
      .then(response => response || fetch(event.request))
  );
});
