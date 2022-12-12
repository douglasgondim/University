
import Vue from 'vue'
import Index from './views/Index.vue'
import router from './router/Router.js'


import BootstrapVue from 'bootstrap-vue'
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'


Vue.use(BootstrapVue);

import './css/reset.css'
import './css/global.css'



Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(Index),
}).$mount('#app')
