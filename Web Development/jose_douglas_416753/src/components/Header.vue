<template>
  <div class="header">
    <h1 id="main-title">Sistema X</h1>
  </div>
</template>


<script>
export default {
  name: "Header"
};
</script>

<style>
.header {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  /* margin-top: 0px; */
  background: rgb(214, 214, 214);
  height: 100px;
  display: flex;
  justify-content: center;
  align-items: center;
}
.header h1 {
  font-size: 40px;
}
#main-title {
  font-family: fantasy;
  font-weight: 600;
  /* text-decoration: underline */
}
</style>
