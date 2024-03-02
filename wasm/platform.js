export default class Platform {

	/**
	* @param {CanvasRenderingContext2D} ctx 
	* @param {WebAssembly} ctx 
	* */
	constructor(ctx) {
		this.ctx = ctx;
		this.buffer = undefined;
		this.function_table = undefined;
		this.width = 0;
		this.height = 0;
	}

	/**
	* @param {number} str_ptr 
	* @param {number} w 
	* @param {number} h 
	* */
	Platform_init_window(w, h, str_ptr) {
		this.width = w;
		this.height = h;

		this.ctx.canvas.width = this.width;
		this.ctx.canvas.height = this.height;
		document.title = cstr_by_ptr(this.buffer, str_ptr);
	}

	/** @param {number} color  */
	Platform_clear_background(color) {
		this.ctx.fillStyle = color_to_hex(color);
		this.ctx.clearRect(0, 0, this.width, this.height);
		this.ctx.fillRect(0, 0, this.width, this.height);
	}

	/**
	* @param {number} min 
	* @param {number} max 
	* */
	Platform_rand_range(min, max) {
		return min + Math.random() * (max - min);
	}

	/** @param {Number} fn_ptr */
	Platform_set_loop(fn_ptr) {
		this.loop_fn = this.func_table.get(fn_ptr);
	}

	/**
	* @param {number} x 
	* @param {number} y
	* @param {number} radius
	* @param {number} color
	* */
	Platform_draw_point(x, y, radius, color) {
		this.ctx.beginPath();
		this.ctx.arc(x, y, radius, 0, 2 * Math.PI, false);
		this.ctx.fillStyle = color_to_hex(color);
		this.ctx.fill();
	}

	/**
	* @param {number} mem_usage 
	* */
	Platform_log_mem(mem_usage) {
		console.info(`Mem usage: ${(mem_usage * 100).toFixed(2)}%`);
	}

	Platform_rand_seed() {}
	Platform_begin_draw() {}
	Platform_end_draw() {}
	Platform_close_drawing() {}
}

/**
* @param {number} color 
* */
function color_to_hex(color) {
	const r = ((color>>(0*8))&0xff).toString(16).padStart(2, "0");
	const g = ((color>>(1*8))&0xff).toString(16).padStart(2, "0");
	const b = ((color>>(2*8))&0xff).toString(16).padStart(2, "0");
	const a = ((color>>(3*8))&0xff).toString(16).padStart(2, "0");
	return '#'+r+g+b+a;
}

/**
* @param {ArrayBuffer} buffer 
* @param {number} str_ptr 
* @returns {string}
* */
function cstr_by_ptr(buffer, str_ptr) { 
	const mem = new Uint8Array(buffer);
	const len = cstr_len(mem, str_ptr);
	const str_bytes = new Uint8Array(buffer, str_ptr, len);

	return new TextDecoder().decode(str_bytes);
}

/**
* @param {Uint8Array} buffer 
* @param {number} str_ptr 
* @returns {number}
* */
function cstr_len(mem, str_ptr) {
	let len = 0;
	while (mem[str_ptr++] != 0) {
		len++;
	}
	return len;
}
