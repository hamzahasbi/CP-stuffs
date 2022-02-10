// Converts a URL Query String into an object map
function convertQueryToMap(query) {
  const q = decodeURI(query).split('&');
  const res = new Map();
  let roots = [];

  q.forEach(el => {
    const param = el.split('=');
    const conf = param[0].split('.');
    const val = param[1];
    let last = null;
    const len = conf.length;
    conf.reverse().forEach((curr, ind) => {
      if (ind >= 1) {
        last = conf[ind - 1];
      }
      if (ind == len - 1) {
        roots.push(curr);
      }
      if (last) {
        if (res.has(curr)) {
          const update = res.get(curr);
          update.push(last);
          res.set(curr,[...new Set(update)]);
        } else {
          res.set(curr, [last]);
        }
      }
      else {
        res.set(curr, [val]);
      }
    }) 
  });
  roots = [...new Set(roots)];
  const vis = new Map();
  const render = {};
  roots.forEach(el => {
    bfs(el, res, vis, render);
  });
  console.log(vis);
  // console.log(render);
}

function bfs(node, graph, vis, render) {
  const queue = [node];
  vis.set(node, [1, null]);
  while(queue.length) {
    const prop = queue.shift();
    if (graph.has(prop)) {
      graph.get(prop).forEach(v => {
        if (!vis.has(v)) {
          const level = vis.get(prop);
          vis.set(v, [level[0] + 1, prop]);
          queue.push(v);
        }
      })
    }
  }
}

const q = 'user.name.firstname=Bob&user.name.lastname=Smith&user.favoritecolor=Light%20Blue&color=4';
const out = {
  'user': {
    'name': {
      'firstname': 'Bob',
      'lastname': 'Smith'
    },
    'favoritecolor': 'Light Blue'
  }
};
convertQueryToMap(q);
// https://www.codewars.com/kata/5286d92ec6b5a9045c000087/train/javascript