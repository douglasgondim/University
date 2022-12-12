import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import AddLivros from '../views/AddLivros'
import Chapters from '../views/Chapters'


Vue.use(VueRouter);

export default new VueRouter({
    routes: [
        {
            path: '/',
            name: 'Home',
            component: Home
        },
        {
            path: '/adicionar_livros',
            name: 'AddLivros',
            component: AddLivros
        },
        {
            path: '/:id/capitulos/',
            name: 'Capitulos',
            component: Chapters,
        }
    ]
})